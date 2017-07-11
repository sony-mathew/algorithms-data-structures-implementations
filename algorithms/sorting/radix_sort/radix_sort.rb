class Array

  public

    def radix_sort
      d = self.max.to_s.length
      array = self
      (0...d).each do |digit_pos|
        array = counting_sort(array, 9, digit_pos)
      end
      array
    end

    def counting_sort(array, max_element, digit_pos)
      c = []
      b = []

      (0..max_element).each { c.push(0) }

      (0...size).each do |j| 
        digit = get_digit(array[j], digit_pos)
        c[ digit ] += 1
      end

      (1..max_element).each { |i| c[i] = c[i] + c[i - 1] }

      (0...size).to_a.reverse.each do |j|
        digit = get_digit(array[j], digit_pos)
        b[ c[digit] - 1 ] = array[j]
        c[digit] -= 1
      end

      b
    end

    def get_digit(num, i)
      num_s = num.to_s
      return 0 if i >= num_s.length
      num_s[-1 + i*-1].to_i
    end
end

a = [1811, 76, 92, 43, 890, 567, 7, 289]

puts a.radix_sort.inspect
