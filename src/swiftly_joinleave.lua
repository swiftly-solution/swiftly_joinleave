events:on("OnClientConnect", function(playerid)
    local player = GetPlayer(playerid)
    if not player then return false end

    logger:Write(LogType.Common, FetchTranslation("joinleave.join.logmessage"))
    playermanager:SendMsg(MessageType.Chat, (string.format(FetchTranslation("joinleave.join.message"), player:GetName())))
    return true
end)

events:on("OnClientDisconnect", function(playerid)
    local player = GetPlayer(playerid)
    if not player then return end

    logger:Write(LogType.Common, FetchTranslation("joinleave.leave.logmessage"))
    playermanager:SendMsg(MessageType.Chat, (string.format(FetchTranslation("joinleave.leave.message"), player:GetName())))
end)

events:on("OnPluginStart", function()
    logger:Write(LogType.Warning, "The plugin has started the log session.")
end)

events:on("OnPluginStop", function()
    logger:Write(LogType.Warning, "The plugin has closed the log session.")
end)

function GetPluginAuthor()
    return "Swiftly Solution"
end
function GetPluginVersion()
    return "1.0.0"
end
function GetPluginName()
    return "Join Leave (LUA)"
end
function GetPluginWebsite()
    return "https://github.com/swiftly-solution/swiftly_joinleave"
end
