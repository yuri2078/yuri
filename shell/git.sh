#!/usr/bin/bash
cd "$HOME/yuri" || echo "没有这个目录捏" && exit 0
git add . || echo "add 失败" && exit 0
git commit -m "no changes" || echo "提交失败" && exit 0
git push || echo "push 失败" && exit 0


