#!/bin/bash
# 统计一个文件里单词的词频
cat word.txt | xargs -n 1 | sort | uniq -c | sort -nr | awk '{print $2,$1}'
