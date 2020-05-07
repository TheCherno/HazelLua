
-- This is an example script file

function CreateTempTexture()
	local texture = Texture2D.Create('path/to/file.png')
	local width = texture:GetWidth()
	local height = texture:GetHeight()
	local format = texture:GetFormat()
	local path = texture:GetFilePath()
	print(path)
end

CreateTempTexture()
-- note: unless collectgarbage is called, nothing will
--       be destroyed
collectgarbage()

print("[Lua] Texture should now be destroyed!");

local texture = Texture2D.Create('assets/textures/Texture_Albedo.png')
Renderer.PrintTextureDetailsBase(texture)
Renderer.PrintTextureDetails(texture)