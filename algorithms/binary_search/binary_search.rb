class BinarySearch
  attr_accessor :array, :size

  def initialize
    @array = []
  end

  def start
    read_array
    p @array
    sort_array
    p @array
    search
  end

  def read_array
    puts "What size of array do you want?"
    @size = gets.chomp.to_i
    puts "Enter the elements : "
    @size.times { @array.push(gets.chomp.to_i) }
  end

  def sort_array
    @array.sort!
  end

  def binary_search item
    start = 0
    last = @size - 1
    while start <= last
      mid = (start + last)/2
      if item == @array[mid]
        return mid
      elsif item > @array[mid]
        start = mid + 1
      else
        last = mid - 1
      end
    end
  end

  def search
    puts "Which item do you want to search for? "
    item = gets.chomp.to_i
    pos = binary_search(item)
    if pos
      puts "The item was found at index : #{pos}"
    else
      puts "Sorry. We couldn't find the item in the array."
    end
    puts "Do you want to search for an item again? (y/n)"
    option = gets.chomp
    if option == 'y' || option == 'Y'
      search
    end
  end
end


searchRec = BinarySearch.new
searchRec.start