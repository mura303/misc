#!ruby
# -*- coding: utf-8 -*-

require 'open-uri'
require 'uri'

namelist = nil

File.open( "namelist.txt","r:utf-8" ) do |f|
  namelist = f.readlines.map{|line| line.chomp.split("") }
end

# namelist.txtに空行があっても大丈夫にする
namelist.delete_if{|e| e.length==0 }

# 全ての組み合わせを生成
namearray = namelist.shift
while namelist.length>0
  namearray = namearray.product(namelist.shift).map{|e| e.join}
end

name_resultnum = {}

namearray.each do |name|
  open("http://www.google.com/search?q=#{URI.encode(name)}").read.scan(/Results <b>1<\/b> - <b>10<\/b> of about <b>([\d,]+)<\/b> for <b>/) do |match|
    name_resultnum[name] = match[0].delete(",").to_i
  end
end

name_resultnum.sort{|a,b| b[1]<=>a[1]}.each do |e|
  puts "#{e[0]}, #{e[1]}"
end
