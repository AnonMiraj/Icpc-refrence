#let kactlwarning(msg) = block(width: 100%, fill: orange.lighten(80%))[#msg]
#let kactlerror(msg) = block(width: 100%, fill: red.lighten(80%))[#msg]

#let kactl(
  title: "KACTL",
  subtitle: "KTH Algorithm Competition Template Library",
  team-name: "Team Name",
  team-members: "Team Members",
  university-name: "University",
  university-short: "Uni",
  university-logo: "",
  contest-name: "Contest",
  contest-date: "Date",
  body
) = [
  // === Font setup ===
  #set text(font: ("New Computer Modern", "TeX Gyre Cursor"), size: 9pt)

  // === Page setup: A4 landscape, tight margins ===
  #set page(
    paper: "a4",
    flipped: true,
    margin: (left: 0.5cm, right: 0.5cm, top: 1.0cm, bottom: 0.4cm),
  )

  #set par(justify: true, leading: 0.5em)
  #set par(spacing: 0.4em)

  #set heading(numbering: "1.1.1")

  // Chapter headings: huge, bold, underlined title with number on next line
	#show heading.where(level: 1): it => {
		v(0.6em)
		context {
			if it.numbering == none {
				// Unnumbered chapter-style heading (e.g. the outline's "Contents" title)
				underline(text(size: 18pt, weight: "bold", it.body))
			} else {
				let num = counter(heading).at(it.location()).first()
				let num-str = numbering(it.numbering, num)
				underline(text(size: 18pt, weight: "bold", it.body))
				text(size: 18pt, weight: "bold")[(#num-str) ]
			}
		}
		v(0.4em)
	}

  // Section headings: LARGE, bold, with numbering pass-through (matching LaTeX \LARGE ~17pt)
  #show heading.where(level: 2): it => {
    v(0.25em)
    block(
      width: 100%,
      breakable: false,
      text(size: 17pt, weight: "bold", it)
    )
    v(0.2em)
  }

  // Subsection headings: large, bold, with numbering pass-through (matching LaTeX \large ~12pt)
  #show heading.where(level: 3): it => {
    v(0.5em)
    block(
      width: 100%,
      breakable: false,
      text(size: 12pt, weight: "bold", it)
    )
    v(0.1em)
  }

  // Subsubsection headings: large, bold, with numbering pass-through (matching LaTeX \large ~12pt)
  #show heading.where(level: 4): it => {
    v(0.5em)
    block(
      width: 100%,
      breakable: false,
      text(size: 12pt, weight: "bold", it)
    )
    v(0.5em)
  }

  // === Team page (no header, no page number) ===
  #if team-name != "" [
    #page(margin: (top: 3cm, bottom: 1cm, left: 1cm, right: 1cm))[
      #align(center)[
        #if university-logo != "" [
          #image(university-logo, width: 3cm)
          #v(0.5cm)
        ]
        #v(1cm)
        #text(size: 25pt, university-name)
        #v(0.7cm)
        #text(size: 60pt, weight: "bold", team-name)
        #v(0.5cm)
        #text(size: 20pt, team-members)
        #v(1fr)
        #text(size: 21pt, contest-name)
        #v(0.5cm)
        #text(size: 20pt, contest-date)
        #v(1cm)
      ]
    ]
    #pagebreak()
  ]

  // === Header: filenames in center + column rules on pages with new listings ===
  #set page(
    header: context {
      let p = counter(page).get().first()
      if p >= 3 {
        let page-num = p - 1
        let regs = state("kactl-files", ()).final()
        let names = if type(regs) != "none" and regs != none {
          let curr_files = regs.filter(r => r.at(1) == p).map(r => r.at(0))
          if curr_files.len() > 0 { curr_files } else {
            regs.filter(r => r.at(1) == p - 1).map(r => r.at(0))
          }
        } else {
          ()
        }
        let has-listings = if type(regs) != "none" and regs != none {
          regs.filter(r => r.at(1) == p).map(r => r.at(0)).len() > 0
        } else { false }
        names = names.map(f => {
          if f.starts-with(".") { f }
          else { f.split(".").first() }
        })
        let header-len = names.join("").len()
        let sz = if header-len > 150 { 8pt } else { 10pt }
        set text(size: sz)
        let header-text = block(height: 25pt, grid(
          columns: (auto, 1fr, auto),
          align(left)[#university-short\ ],
          align(center)[
            #for (i, name) in names.enumerate() {
              text(weight: "bold")[#name]
              if i < names.len() - 1 { h(0.5em) }
            }
          ],
          align(right)[ #page-num],
        )) + v(5pt) // headheight 25pt + headsep 5pt (matching LaTeX)
        // Draw column rules only on pages that have new listings
        if has-listings {
          layout(size => {
            // A4 landscape (841.89pt) with 0.5cm margins (14.173pt each), 10pt gutter
            let page-w = 841.89pt
            let margin-side = 14.173pt
            let content-w = page-w - 2 * margin-side  // 813.544pt
            let gutter = 10pt
            let col-w = (content-w - 2 * gutter) / 3  // 264.515pt
            // Absolute positions from page left edge:
            // boundary1 = margin-side + col-w + gutter/2
            // boundary2 = margin-side + 2*col-w + gutter + gutter/2
            // place dx is relative to page center (page-w/2)
            let x1 = margin-side + col-w + gutter / 2 - page-w / 2
            let x2 = margin-side + 2 * col-w + gutter + gutter / 2 - page-w / 2
            let r1 = place(dx: x1, dy: -size.height / 2, rect(width: 0.5pt, height: size.height, fill: black))
            header-text + r1 
          })
        } else {
          header-text
        }
      }
    },
  )

  // === Main content - 3 columns with 10pt gutter ===
  #set columns(gutter: 10pt)
  #show: columns.with(3)

  // Custom table of contents - chapters only with number and page
  // Appendix chapters are excluded
  #show outline.entry.where(level: 1): it => {
    let hdg = it.element
    context {
      let is_appendix = hdg.numbering != none and hdg.numbering != "1.1.1"
      if not is_appendix {
        let pg = counter(page).at(hdg.location()).first() - 1
        let num = counter(heading).at(hdg.location()).first()
        grid(
          columns: (auto, 1fr, auto),
          column-gutter: 0.5em,
          text(weight: "bold", [#num.]),
          hdg.body,
          text(weight: "bold", [#pg]),
        )
        v(2pt)
      }
    }
  }
  #v(1em)

  #body
]

// Register a source file for the page header.
// Each call records (filename, page_number) via global state.
// Must be called inside a #context block to access counter(page).
#let kactlref(caption) = {
  context {
    let p = counter(page).get().first()
    state("kactl-files", ()).update(regs => regs + ((caption, p),))
  }
}
