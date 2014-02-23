local max = io.read("*number")
local money = io.read("*number")
local list = {}
for i=1,max do
	list[#list + 1] = io.read("*number")
end
table.sort( list )
local cost = 0
for i,v in ipairs(list) do
	cost = cost + v
	if cost > money then
		print(i - 1)
	end
end