"General editor settings
set tabstop=4
set nocompatible
set shiftwidth=4
set expandtab
set autoindent
set clipboard=unnamedplus
set smartindent
set ruler
set showcmd
set incsearch
set shellslash
set number
set relativenumber
set cino+=L0 
syntax on
filetype indent on
filetype off
setlocal indentkeys-=:
"inoremap >= ≥
"inoremap <= ≤
"inoremap != ≠
"inoremap -> →
"inoremap <- ←
 
"Theme (requires Solarized Light terminal theme to work properly)
set termguicolors
set t_Co=256
"set background=dark
set background=light
syntax on
"colorscheme solarized
 
"keybindings for { completion, "jk" for escape, ctrl-a to select all
inoremap {<CR>  {<CR>}<Esc>O
inoremap {}     {}
imap jk         <Esc>
map <C-a> <esc>ggVG<CR>
set belloff=all
 
"Append template to new C++ files
autocmd BufNewFile *.cpp 0r /home/lambd47/vimcp/Library/Template.cpp
 
"Compile and run
"Note that the next uncommented line requires the build.sh script!
"Replace it with the commented line below if you don't have it
"set makeprg=g++\ -static\ -DDEBUG\ -lm\ -s\ -x\ c++\ -Wall\ -Wextra\ -O2\ -std=c++17\ -o\ %:r\ %
set makeprg=build.sh\ %:r
autocmd filetype cpp nnoremap <F9> :w <bar> Make <CR>
"autocmd filetype cpp nnoremap <F9> :w <bar> !build.sh %:r in out <CR>
autocmd filetype cpp nnoremap <F8> :vertical terminal ++shell ++cols=40 ./%:r <CR>
autocmd filetype cpp nnoremap <F11> :!./%:r<CR>

"Plugin setup
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'lervag/vimtex'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'tpope/vim-dispatch'
Plugin 'xuhdev/vim-latex-live-preview'
Plugin 'morhetz/gruvbox'
Plugin 'sainnhe/everforest'
Plugin 'NLKNguyen/papercolor-theme'
Plugin 'crusoexia/vim-monokai'
Plugin 'vim-airline/vim-airline'
Plugin 'tonsky/firacode'
Plugin 'Rainbow-Parenthesis'
Plugin 'dracula/vim', { 'name': 'dracula' }
Plugin 'phanviet/vim-monokai-pro'
call vundle#end()
"colorscheme monokai
colorscheme monokai_pro
"colorscheme everforest
"colorscheme solarized
"colorscheme gruvbox
"colorscheme dracula
filetype plugin indent on

