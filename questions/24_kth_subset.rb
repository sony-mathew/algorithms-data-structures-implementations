=begin
Given an array of N elements, consider all subsets ( 2^^N ), now sort the subsets based upon the sum of elements in it, and then find the K'th subset from the list of sorted subsets. expected complexity O(NK). 
Eg. array = {1,2,3}
Subsets sorted acc. to sum
{ Phi }
{1}
{2}
{1,2}
{3}
{1,3}
{2,3}
{1,2,3}

for K = 4, ans can be either {1,2} or {3}
=end

class Array
  def counting_sort
    max = self.max
    count_arr = []

    # intialize the count_arr elemnets to zero
    (max + 1).times { |i| count_arr.push(0) }

    # getting counts of the elements in the initial array
    self.each { |el| count_arr[el] += 1 }

    # incremental count of count_arr
    1.step(max, 1).each do |i|
      count_arr[i] = count_arr[i - 1] + count_arr[i]
    end

    result = []

    # putting the elements in its correct indexes
    self.size.times.each do |i|
      result[count_arr[self[i]] - 1] = self[i]
      count_arr[self[i]] -= 1
    end

    result
  end
end

# def get_kth_subset(arr, k)
  
#   # genrate all subsets of a given set in order
#   # total 2 ^ n subsets are there
#   # total = 1 << arr.size

#   # 0.step(total - 1, 1).each do |i|
#   #   sum = 0
#   #   new_arr = []

#   #   0.step(i - 1, 1).each do |j|
#   #     if (i & (1 << j)) > 0
#   #       sum += arr[j]
#   #       new_arr << arr[j]
#   #     end
#   #   end
#   # end

#   new_arr = []
#   # get only kth subset
#   0.step(k - 2, 1).each do |j|
#     new_arr << arr[j] if ((k - 1) & (1 << j)) > 0
#   end
#   new_arr
# end

def kth_subset(old_subsets, current_el, k)
  temp = []
  current_list = []
  current_list.push(current_el)

  old_subsets.each do |s|
    temp.push(s + current_list)
  end

  new_subset = old_subsets + temp

  new_subset.sort_by { |s| s.reduce(0, :+) }

  req_range = (k > new_subset.size - 1) ? k : -1
  new_subset[0..req_range]
end

def init
  k = 600000
  arr = gets.chomp()
  arr = arr.split(',').map(&:strip).map(&:to_i)
  arr = arr.counting_sort
  # get_kth_subset(arr, 600000)

  req_subsets = [[]]
  arr.size.times.each do |i|
    req_subsets = kth_subset(req_subsets, arr[i], k)
  end
  req_subsets[k - 1]
end

init
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
