#import "template.typ": *
#import "@preview/mitex:0.2.7": mi, mitex

#kactl(
  title: "KACTL",
  subtitle: "KTH Algorithm Competition Template Library",
  team-name: "شجر اللمون دبلان على أرضه",
  team-members: "Ezzeldin, Ramez, Zeyad Zahran",
  university-name: "OwO",
  university-short: "Cipher",
  university-logo: "tex/cipher.pdf",
  contest-name: " ",
  contest-date: "WELL",
)[
	#outline(depth: 1)
	#include "contest/chapter.typ"
  #include "math/chapter.typ"
  #include "data-structures/chapter.typ"
  #include "numerical/chapter.typ"
  #include "number-theory/chapter.typ"
  #include "combinatorial/chapter.typ"
  #include "graph/chapter.typ"
  // #include "geometry/chapter.typ"
  #include "strings/chapter.typ"
  #include "various/chapter.typ"
#include "appendix/chapter.typ"
]
