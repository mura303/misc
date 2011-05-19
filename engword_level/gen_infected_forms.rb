ARGF.each_line do |line|
  ( word, content ) = line.split( '///' )
  word.strip!
  word.downcase!
  content =~ /ÅyïœâªÅz(.+?)\\/s

  if $1
    forms = []
    $1.downcase.scan( /([a-z,\(,\)]+)/ ).each do |tokens|
      raise if tokens.length != 1
      tok = tokens[0]
      
      if tok =~ /(.*)\((.*)\)(.*)/
        forms << $1 + $3
        forms << $1 + $2 + $3
      else
        forms << tok
      end
    end
    puts "#{word} : #{forms.join(', ')}"
  end

end
