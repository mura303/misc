#!ruby

str = STDIN.gets.strip
k = STDIN.gets.strip.to_i

charnums = Hash.new(0)

str.each_byte do |c|
    charnums[c] += 1
end

delchar = []

charnums.to_a.sort do |a,b|
    (a[1] <=> b[1]) * 2 + (b[0] <=> a[0])    
end.each do |elem|
    if elem[1] <= k
        delchar << elem[0]
        k -= elem[1]
    else
        break
    end
end

delchar.each do |c|
    str.delete("%c"%c)
end

p str
