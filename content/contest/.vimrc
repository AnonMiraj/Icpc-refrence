set cin ar aw ai is ts=4 sw=4 tm=50 nu noeb ru cul sm
syn on | filetype plugin indent on | colo desert

let &makeprg = 'g++ -Wall -Wconversion -Wfatal-errors -g -std=c++17 -fsanitize=undefined,address % -o %<'

map <F5> :w<CR>:make<CR>:!./%< < %<.in ;read && clear <CR><F13>
au BufNewFile *.cpp 0r ./template.cpp
