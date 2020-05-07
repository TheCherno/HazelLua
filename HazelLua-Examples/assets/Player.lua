--
-- This is an example Entity script file
-- The idea here is to attach this script as a component
-- to an Entity in Hazel
--

-- Define type. MUST be unique (at least for entities)
Player = {}

-- Variables used within script can be local like this
local texture;

-- Define functions. Functions MUST belong to a type
function Player.OnCreate()
	texture = Texture2D.Create("PlayerSprite.png")
	print("[Lua] Created!")
end

function Player.OnDestroy()
	print("[Lua] Destroyed!")
end

function Player.OnUpdate(ts)
	print("Updating Player")
	print("Player: " .. texture:GetFilePath())
	print("[Lua] Updated! ", ts)
end

