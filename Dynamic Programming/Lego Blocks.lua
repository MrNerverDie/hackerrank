function expand_row_config_arr( width )
	curr_len = #row_config_arr
	while curr_len <= width do
		a = row_config_arr[#row_config_arr]
		b = row_config_arr[#row_config_arr - 1]
		c = row_config_arr[#row_config_arr - 2]
		d = row_config_arr[#row_config_arr - 3]
		next_num = (a + b + c + d) % 1000000007;
		row_config_arr[#row_config_arr + 1] = next_num
		curr_len = curr_len + 1
	end
end

row_config_arr = {0, 1, 2, 4, 8}

tests_num = io.read()
for i=1,tests_num do
	N, M = io.read():match("(%d+) (%d+)")

	if #row_config_arr <= tonumber(M) then
		expand_row_config_arr(M)
	end

	T = {0, 1}

	S = {0, 1}

	U = {0, 0}

	for k = 3, M + 1 do	
		T[#T + 1] = math.pow(row_config_arr[k], N) % 1000000007

		U[#U + 1] = 0
		-- print(#U)
		for l=2,k - 1 do
			U[k] = (U[k] + S[l] * T[k - l + 1])
		end
		U[k] = U[k] % 1000000007

		-- print(T[k])
		-- print(U[k])
		S[#S + 1] = (T[k] - U[k]) 
	end

	print(S[#S])
end