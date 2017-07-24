# this is a multi-line comment in ruby
=begin
https://www.hackerrank.com/challenges/ctci-making-anagrams
=end

a = gets.strip
b = gets.strip

freq_count_a = a.split('').group_by{ |a| a[0] }.map {|k, v| [k, v.count]}.to_h
count = 0
b.split('').each do |k|
  if freq_count_a[k] && freq_count_a[k] > 0
    freq_count_a[k] -= 1
  else
    count += 1
  end
end

count += freq_count_a.values.sum

puts count