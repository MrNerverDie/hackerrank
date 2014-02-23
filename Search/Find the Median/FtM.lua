local max = tonumber(io.read())
local bag = {}
for i=1,max do
	local element = io.read("*number")
	bag[element] = (bag[element] or 0) + 1
end
local mid = max / 2 + 0.5
local count = 0
for element=-10000,10000 do
	if bag[element] then
		count = count + bag[element]
		if count >= mid then
			print(element)
			break;
		end
	end
end