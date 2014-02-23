-- -- Util
-- function premgen( a, n )
-- 	n = n or #a
-- 	if n <= 1 then
-- 		coroutine.yield(a)
-- 	else
-- 		for i = 1, n do
-- 			a[n], a[i] = a[i], a[n]
-- 			premgen(a, n - 1)
-- 			a[n], a[i] = a[i], a[n]
-- 		end
-- 	end
-- end

-- function permutations( a )
-- 	local co = coroutine.create(function (  ) premgen(a) end)
-- 	return function ( ... )
-- 		local code, res = coroutine.resume(co)
-- 		return res
-- 	end
-- end
-- -- Util

local T = io.read("*number")
for i=1,T do
	local N = io.read("*number")
	local K = io.read("*number")
	local A = {}
	local B = {}
	for i=1,N do
		A[i]= io.read("*number")
	end
	for i=1,N do
		B[i]= io.read("*number")
	end
	table.sort( A )
	table.sort( B )
	local permOK = true
	for i=1,N do
		if A[i] + B[N + 1 - i] < K then
			permOK = false
		end 
	end
	-- local permOK = true
	-- for Ai in permutations(A) do
	-- 	permOK = true
	-- 	for Bi in permutations(B) do
	-- 		permOK = true
	-- 		for i = 1, N do
	-- 			if Ai[i] + Bi[i] < K then
	-- 				permOK = false
	-- 				break;
	-- 			end
	-- 		end
	-- 		if permOK then
	-- 			break;
	-- 		end
	-- 	end
	-- 	if permOK then
	-- 		break;
	-- 	end
	-- end
	if permOK then
		print("YES")
	else
		print("NO")
	end
end