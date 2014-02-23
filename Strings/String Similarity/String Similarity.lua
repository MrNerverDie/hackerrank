function cal_similarity(line, begin, length, count_init)
	count = count_init

	if (count < 0) then
		count = 0
	end

	for i = begin + count, length do
		if line:byte(i) == line:byte(i - begin + 1) then
			count = count + 1
		else
			return count
		end
	end
	return count
end

input = io.input("./input.txt")
case_num = input:read()
for i=1,case_num do
	line = input:read()
	length = line:len()
	sum_count = length
	same_count = cal_similarity(line, 2, length, 0) + 1
	count_init = same_count - 3 + 1
	sum_count = sum_count + same_count - 1
	print("same_count : " .. same_count)
	for i=3,length do
		count = cal_similarity(line , i, length, count_init)
		if (count > same_count) then
			count_init = same_count - 1
		else
			count_init = count - 1
		end
		sum_count = sum_count + count
	end
	print(sum_count)
end
