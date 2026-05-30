set nocompatible
syntax on
filetype plugin indent on
set nu rnu ts=4 sw=4 et ai si ruler mouse=a incsearch showcmd
set cino+=L0
set belloff=all
set background=dark 
inoremap {<CR> {<CR>}<Esc>O
inoremap {} {}
imap jk <Esc>
autocmd BufNewFile *.cpp 0r ~/template.cpp
autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -Wall -Wextra -O2 -std=c++17 % -o %:r<CR>
autocmd filetype cpp nnoremap <F8> :vertical terminal ++shell ++cols=40 ./%:r<CR>
autocmd filetype cpp nnoremap <F11> :!./%:r<CR>
