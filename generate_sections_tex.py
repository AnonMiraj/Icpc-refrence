
import os
import re

def extract_ordered_name(name):
    match = re.match(r'^(\d+)[-_](.+)', name)
    if match:
        order = int(match.group(1))
        clean_name = match.group(2)
    else:
        order = float('inf')
        clean_name = name
    return order, clean_name

def get_latex_style(file_path):
    ext = os.path.splitext(file_path)[1]
    if ext == ".cpp":
        return "cpp"
    elif ext == ".sh":
        return "others"
    elif ext == ".txt":
        return "txt"
    elif ext == ".tex":
        return None  # use \input instead
    else:
        return "others"

def format_subsection_name(name):
    name = os.path.splitext(name)[0]
    _, name = extract_ordered_name(name)
    return name.replace("_", " ").replace("&&", r"\&\&").title()

def collect_ordered_structure(base_dir="cod"):
    sections = []

    for section_folder in os.listdir(base_dir):
        section_path = os.path.join(base_dir, section_folder)
        if not os.path.isdir(section_path):
            continue
        section_order, section_clean = extract_ordered_name(section_folder)

        files = []
        for file in os.listdir(section_path):
            file_path = os.path.join(section_path, file)
            if not os.path.isfile(file_path):
                continue
            file_order, file_clean = extract_ordered_name(file)
            files.append((file_order, file_clean, os.path.join(section_folder, file)))

        files.sort()
        sections.append((section_order, section_clean, files))

    sections.sort()
    return sections

def generate_latex(sections, output_file="src/sections.tex"):
    with open(output_file, "w") as f:
        for _, section_name, files in sections:
            f.write(f"\\section{{{section_name.title()}}}\n")
            for _, file_clean, rel_path in files:
                style = get_latex_style(rel_path)
                subsection = format_subsection_name(os.path.basename(file_clean))
                tex_path = f"cod/{rel_path.replace(os.sep, '/')}"
                if style is None and tex_path.endswith(".tex"):
                    f.write(f"\\subsection{{{subsection}}}\n")
                    f.write(f"\\raggedbottom \\input {tex_path}\n")
                else:
                    f.write(f"\\subsection{{{subsection}}}\n")
                    f.write(f"\\raggedbottom\\lstinputlisting[style={style}]{{{tex_path}}}\n")
                f.write("\\hrulefill\n")
            f.write("\n")

if __name__ == "__main__":
    sections = collect_ordered_structure("cod")
    generate_latex(sections,"src/sections.tex")

