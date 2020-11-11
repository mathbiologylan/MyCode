let mapleader=" " "将leader键（\）设置为空格键
syntax on "代码高亮
set number "设置行号
set norelativenumber "关闭相对行号
"set cursorline "设置光标下划线
set wrap "使键入内容不会超出屏幕边界（相当于换行）
set showcmd "命令展示
set wildmenu "提示
set hlsearch "搜索高亮
set incsearch "一边输入一边高亮
exec "nohlsearch"
set ignorecase "搜索时忽略大小写
set smartcase "搜索时智能大小写
"tab设置
set tabstop=4       " Tab键替换的空格长度，默认8
set softtabstop=4   " 退格键退回缩进空格的长度
set shiftwidth=4    " 表示每一级缩进的长度
set expandtab       " 设置缩进用空格来表示
set autoindent      " 设置自动缩进
set smarttab
set backspace=indent,eol,start

set linespace=6 "设置行距

noremap u l "以u代替l
noremap l u "以u代替l
noremap <LEADER><CR> :nohlsearch<CR> "按下空格加回车取消搜索结果高亮显示

map s <nop> "按下s不做任何操作（本来应该是按下s删除当前字符并进入插入模式）
map S :w<CR> "按下S保存
map Q :q<CR> "按下Q退出
map R :source $MYVIMRC<CR> "按下R自动刷新配置文件

"gruvbox配色方案
color gruvbox
set background=dark

"插件安装
call plug#begin('~/.vim/plugged')

Plug 'vim-airline/vim-airline' "状态栏插件
Plug 'neoclide/coc.nvim',{'branch': 'release'} "代码补全插件
Plug 'preservim/nerdtree' "nerdtree是一个树形的目录管理插件，可以方便在nvim中进行当前文件夹中的文件切换
Plug 'Xuyuanp/nerdtree-git-plugin' "显示git状态标志的NERDTree插件
Plug 'Yggdroot/indentLine' "提供可视化缩进
Plug 'luochen1990/rainbow' "提供嵌套括号高亮
Plug 'majutsushi/tagbar' "展示当前文件的一些函数
Plug 'octol/vim-cpp-enhanced-highlight' "加强C++高亮

call plug#end()

let g:coc_disable_startup_warning = 1

"molokai配色方案
"color molokai
"配色方案设置
"let g:molokai_original = 1
"let g:rehash256 = 1
"set background=light "配色方案背景设置

"nerdtree设置
autocmd vimenter * NERDTree "启动vim时自动打开tree结构
"未指定具体文件打开tree结构
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif
"修改目录图标
let g:NERDTreeDirArrowExpandable = '+'
let g:NERDTreeDirArrowCollapsible = '-'
"显示隐藏文件
"let NERDTreeShowHidden=1

"indentline--缩进线设置
"竖版缩进指示线
let g:indentLine_enabled = 1 "默认启用indentLine插件
let g:indentLine_char_list = ['|', '¦', '┆', '┊']
"为不同的缩进级别指定缩进符号
let indentLine_showFirstIndentLevel = 1 "显示缩进级别
"将前导空格以指定符号显示
let g:indentLine_color_term = 239 "缩进符号颜色
set list lcs=tab:\|\ " 最后面有空格
let g:indentLine_leadingSpaceChar = '˰' "缩进符号形状:˽˰·
let g:indentLine_leadingSpaceEnabled = 1 "默认开启

"常用操作：
"p:粘贴。
"y:复制。
"d:删除。
"c:改变。
"f:查找。
"split:上下分屏
"vsplit:左右分屏
"o:当前光标行下面插入空行并进入插入模式
"大写O:前光标行上面插入空行并进入插入模式

"代码对齐操作
" :{range} {left or right} [margin]
" {range}指需要对那些行进行操作
" [margin]指最终该行首字符据屏幕左边缘的距离，若不指定，则默认紧靠屏幕左边缘
" :1,3 left 5

"跨文件复制：
" 1、打开A文件
" 2、输入":sp"或者":vsp"---水平或者竖直分屏
" 3、按ctrl+w,再按w切换窗口
" 4、使用yy命令复制
" 5、切换窗口按p粘贴

"vim分屏操作：
" https://www.cnblogs.com/manziluo/p/5789700.html

"vim命令替换操作:
"https://www.cnblogs.com/configure/p/10233565.html
"https://blog.51cto.com/andyss/131652

"批量缩进
"在命令模式下输入以下指令：
" '行号1，行号2>/<'
" 解释：>/<分别表示向右/左缩进一个tab
" 例 ':1,10<'表示从第1行到第10行向左缩进一个tab

"复制指定内容到指定位置
" ':行号1,行号2 copy 行号3'
" 解释：将从行号1到行号2的内容复制到行号3

"删除指定行
" ':行号1,行号2d'
" 解释：将从行号1到行号2的内容删除
