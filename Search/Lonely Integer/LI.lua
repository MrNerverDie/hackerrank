local max = tonumber(io.read())
local bag = {}
for i=1,max do
	local element = io.read("number")
	bag[element] = (bag[element] or 0) + 1
end
for k,v in pairs(bag) do
	if v == 1 then
		print(element)
	end
end