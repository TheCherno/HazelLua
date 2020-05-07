--
-- This is an example Entity script file
-- The idea here is to attach this script as a component
-- to an Entity in Hazel
--

-- Define type. MUST be unique (at least for entities)
Enemy = {
	-- Variables can be created inside tables - this
	-- is probably the recommended way
	Texture;
}

-- Define functions. Functions MUST belong to a type
function Enemy.OnCreate()
	Enemy.Texture = Texture2D.Create("DifferentTex.png")
	print("[Lua] Created!")
end

function Enemy.OnDestroy()
	print("[Lua] Destroyed!")
end

function Enemy.OnUpdate(ts)
	print("Updating Enemy")
	print("Enemy: " .. Enemy.Texture:GetFilePath())
	print("[Lua] Updated! ", ts)
end