local cutil = require "cutil"
local t = cutil.split("hello,,world", ",")
if t then 
	for i=1, #t do
	    print(t[i])
	end
end

cutil.set('a', 'aaasdsfkfjsj')
print(cutil.get('a'))

print(cutil.time())
