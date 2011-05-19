#!/usr/bin/ruby

bnc = Hash.new

ARGF.each_line do |line|
  num, word = line.split
  bnc[word] ||= num.to_i
end

File.open( "svlall.txt" ) do |f|
  f.each_line do |line|
    num, word = line.split(/,/).map{ |t| t.chomp }
    #  printf( "% 16s : %s, %d\n", word, num, bnc[word] )
    printf( "%d\n", bnc[word] )
  end
end
