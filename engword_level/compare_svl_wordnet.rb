#!/usr/bin/ruby



ARGF.each_line do |line|

  level, word = line.split(",").map{ |t| t.chomp }

  printf "% 16s : %s", word, level

  ['n', 'v', 'a', 'r'].each do |mode|
    
    IO.popen( "/usr/local/WordNet-3.0/bin/wn #{word} -faml#{mode}" ) do |f|
      f.each_line do |line|
        if line =~ /polysemy count = (\d+)/
          print ", #{mode}#{$1}"
        end
      end
    end
  end

  puts

end
