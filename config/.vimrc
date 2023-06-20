set number
set expandtab
set tabstop=4
set softtabstop=4
set shiftwidth=4 smarttab
set autoindent
set guifont=Monospace\ 16

"for plugin
call plug#begin('~/.vim/plugged')

Plug 'ActivityWatch/aw-watcher-vim'
Plug 'phanviet/vim-monokai-pro'
Plug 'sickill/vim-monokai'
Plug 'SirVer/ultisnips'
Plug 'jiangmiao/auto-pairs'
Plug 'ianding1/leetcode.vim'
Plug 'vim-scripts/AutoComplPop'
Plug 'sheerun/vim-polyglot'
Plug 'preservim/nerdtree'
Plug 'vim-airline/vim-airline'

call plug#end()

"vim-monokai_pro plugin
colorscheme monokai_pro

"to compile cpp code
autocmd BufRead,BufNewFile *.cpp nnoremap <F5> :w<CR>:!g++ -o %:r % && ./%:r<CR>
set makeprg=g++\ -o\ %:r\ %

"leetcode.vim plugin
let g:leetcode_browser = "firefox"
let g:leetcode_solution_filetype = "cpp"

