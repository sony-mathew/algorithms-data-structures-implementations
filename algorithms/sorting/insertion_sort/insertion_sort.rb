class Array
  def insertion_sort!
    (1...size).each do |i|
      key = self[i]
      ptr = i - 1
      
      while(ptr >= 0 && key < self[ptr])
        self[ptr + 1] = self[ptr]
        ptr -= 1
      end

      self[ptr + 1] = key
    end
  end
end


def interact
  puts "What size array do you want?"
  size = gets.chomp.to_i

  array = []
  puts "Enter the array : "
  size.times { array.push(gets.chomp.to_i) }

  puts "Current array : "
  puts array.inspect

  array.insertion_sort!

  puts "Sorted array : "
  puts array.inspect
end

interact