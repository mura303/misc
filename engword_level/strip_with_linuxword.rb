#!/usr/bin/ruby

words = []

File.open("/usr/share/dict/linux.words") do |f|
  f.each_line do |line|
    words << line.chomp
  end
end

ARGF.each_line do |line|
  if words.include? line.split[1]
    puts line
  end
end
