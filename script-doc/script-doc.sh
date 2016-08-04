#!/bin/bash
# (c) Evol Online 2016
# Author: Reid

function html_header {
    sed -i '1i <!DOCTYPE html> \
<html><head> \
<title>'"$description"'</title> \
</head><body> \
<h1>'"$description"'</h1>' $output_location
}

function html_footer {
    echo "</body></html>" >> $output_location
}

function html_formating {
    sed -i 's/^[-]{39,40}$/<hr>/g' $output_location
}

function html_href {
    for fun in $functions
    do
        sed -i "s/'$fun'/'<a href=\#$fun\>$fun<\/a>'/g" $output_location
    done
}

function table_content {
    sed -i \
        '1i <a name=\"table_content\"><h2>Table of contents:</h2></a>' \
        $output_location
    sed -i '2i '"<ul>" $output_location
    j=3

    for fun in $functions
    do
        if [ "$previous_fun" != "$fun" ]
        then
            sed -i \
                "$j"'i '"<li><a href=\#$fun\>$fun</a></li>" \
                $output_location
            ((j++))
        fi

        previous_fun="$fun"
    done

    sed -i "$j"'i '"</ul>" $output_location
}

function document_indexed {
    function_id=0
    fun_line_to_skip=0
    current_line=2

    echo "<pre>" >> $output_location

    while read unformatedline
    do
        line=`echo "$unformatedline" |
              sed 's/\&/\&amp;/g;s/</\&lt;/g;s/>/\&gt;/g'`

        if [ ${functions_number[$function_id]} == $fun_line_to_skip ] \
        && [ $fun_line_to_skip == $current_line ]
        then
            echo "<b>$line</b>" >> $output_location
            fun_line_to_skip=$(($current_line+1))

            if [ $(($function_id+1)) != ${#functions_number[@]} ]
            then
                ((function_id++))
            fi
        elif [ ${functions_number[$function_id]} == $current_line ]
        then
			anchor=`echo "$line" |
                    tr ";(*\t" "    " |
                    cut -d " " -f2`
            echo \
"<a href=\"#table_content\">Return to the table of contents</a>
</pre>
<hr>
<pre>

<b><a name=\"$anchor\">$line</a></b>" >> $output_location

            if [ $(($function_id+1)) != ${#functions_number[@]} ]
            then
                ((function_id++))
                fun_line_to_skip=$(($current_line+1))
            fi
        else
            echo "$line" >> $output_location
        fi

        ((current_line++))
    done < $input_location

    echo "</pre>" >> $output_location
}

function line_number_of_functions
{
    grep -ne "^*[a-zAZ0-9_].*[);]$" < $input_location |
            tr ":*" "  " |
            cut -d " " -f1
}

# Variables
description="Evol Online -- Hercules Script Commands"
herc_script_location="../../docs/server/scripts/script_commands.txt"
evol_script_location="../../docs/server/scripts/evol_script_commands.txt"
input_location="concat_file.txt"
output_location="script-doc.html"
cat $herc_script_location $evol_script_location > $input_location
functions_number=( `grep -ne "^*[a-zAZ0-9_].*[);]$" < $input_location |
                    tr ":*" "  " |
                    cut -d " " -f1` )
functions=`grep -e "^*[a-zAZ0-9_].*[);]$" < $input_location |
           tr ";(*\t" "    " |
           cut -d " " -f2`

# Remove the previous output file and concat both script command docs.
rm -f $output_location

# Table of content redirecting to each functions.
document_indexed
table_content

# Proper HTML formating.
html_header
html_footer
html_formating
html_href

# Remove the temp concat file.
rm -f $input_location
