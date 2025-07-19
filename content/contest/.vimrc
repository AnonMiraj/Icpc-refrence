set cin ar aw ai is ts=4 sw=4 tm=50 nu noeb bg=dark ru cul sm
syn on | filetype plugin indent on | colo zaibatsu | no ; :
" Select region and then type :Hash to hash your selection.
" Useful for verifying that there aren't mistypes.
command! Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
let &makeprg = 'g++ -Wall -Wconversion -Wfatal-errors -g -std=c++17 -fsanitize=undefined,address % -o %<'

map <F5> :w<CR>:make<CR>:!./%< < %<.in<CR>

au BufNewFile *.cpp 0r ./template.cpp
