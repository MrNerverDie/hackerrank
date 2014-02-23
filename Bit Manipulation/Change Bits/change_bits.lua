local lines = {}
for line in io.lines() do lines[#lines + 1] = line end
local N, Q = string.match(lines[1], "(%d+) (%d+)")

lines[2]:reverse()
local A = {} 
lines[2]:gsub('%d', function(n) A[#A + 1] = n end)

lines[3]:reverse()
local B = {}
lines[3]:gsub('%d', function(n) B[#B + 1] = n end)

local C = {}

local function set(signal, index, value)
	if signal == 'a' then
		A[index] = value
	else 
		B[index] = value
	end
end

local function get(index)
	local carry = 0
	for i=1, N do
		local sum = A[i] + B[i] + carry
		if sum == 3 then
			C[i] = '1'
			carry = 1
		elseif sum == 2 then
			C[i] = '0'
			carry = 1
		elseif sum == 1 then
			C[i] = '1'
			carry = 0
		else
			C[i] = '0'
			carry = 0
		end
	end

	if (carry == 1) then
		C[N + 1] = '1'
	else 
		C[N + 1] = '0'
	end

	return C[index]
end

for i=4,#lines do
	local parameters = {}
	lines[i]:gsub('%d+', function(n) parameters[#parameters + 1] = n end)
	-- for i,v in ipairs(parameters) do
	-- 	print(i,v + 1)
	-- end
	if string.sub(lines[i], 1, 3) == "set" then
		set(lines[i]:sub(5, 5), parameters[1] + 1, parameters[2])
	else
		io.write(get(parameters[1] + 1))
	end
end