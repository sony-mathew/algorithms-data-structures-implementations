class Array

  public

    def counting_sort(max_element)
      c = []
      b = []

      (0..max_element).each { |i| c.push(0) }

      (0...size).each { |j| c[self[j]] += 1 }

      (1..max_element).each { |i| c[i] = c[i] + c[i - 1] }

      (0...size).to_a.reverse.each do |j|
        b[ c[ self[j] ] - 1 ] = self[j]
        c[ self[j] ] -= 1
      end

      b
    end
end

a = [ 23, 120, 54, 11, 8, 67, 3, 1, 48, 77 ]
puts a.counting_sort(120).inspect