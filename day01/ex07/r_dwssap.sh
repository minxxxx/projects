echo "FT_LINE1:"

read FT_LINE1



echo "FT_LINE2:"

read FT_LINE2



cat /etc/passwd | grep -v "#" | cut -d ":" -f 1 | rev | sort -r | sed -n $FT_LINE1,${FT_LINE2}p | \sed -e "s/ /,/g" | tr '\n' ','
