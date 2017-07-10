class Array
  def selection_sort!
    size.times do |i|
      smallest = self[i]
      pos = i
      
      ((i + 1)...self.size).each do |j|
        if smallest > self[j]
          smallest = self[j]
          pos = j
        end
      end

      if pos != i
        self[pos] = self[i]
        self[i] = smallest
      end
    end
  end
end

def interact
  puts "What size array do you want?"
  size = gets.chomp.to_i

  array = []
  puts "Enter the array elements : "
  size.times { array.push(gets.chomp.to_i) }

  puts "Current array is : "
  puts array.inspect

  array.selection_sort!

  puts "Sorted array is : "
  puts array.inspect
end

interact