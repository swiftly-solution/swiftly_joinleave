#include <swiftly/swiftly.h>
#include <swiftly/gameevents.h>
#include <swiftly/server.h>
#include <swiftly/logger.h>
#include <swiftly/configuration.h>

Configuration *config = nullptr;
Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Logger *logger = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);
    g_playerManager = new PlayerManager();
    server = new Server();
    logger = new Logger(mainFilePath, pluginName);
    config = new Configuration();
}

bool OnClientConnect(Player *player)    
{
    if (!player->IsFakeClient())
    {
        g_playerManager->SendMsg(HUD_PRINTTALK, FetchTranslation("joinleave.join.chatmessage"), player->GetName());
        logger->Write(LOGLEVEL_COMMON, FetchTranslation("joinleave.join.logmessage"), player->GetName());
    }  
    return true;  
}

void OnClientDisconnect(Player *player)
{
    if (!player->IsFakeClient())
    {
        g_playerManager->SendMsg(HUD_PRINTTALK, FetchTranslation("joinleave.leave.chatmessage"), player->GetName());
        logger->Write(LOGLEVEL_COMMON, FetchTranslation("joinleave.leave.logmessage"), player->GetName());
    }
}

void OnPluginStart()
{
    logger->Write(LOGLEVEL_WARNING, "The plugin started the log session.");
}

void OnPluginStop()
{
    logger->Write(LOGLEVEL_WARNING, "The plugin has closed the log sesion.");
}

const char *GetPluginWebsite()
{
    return "https://github.com/swiftly-solution/swiftly_joinleave";
}

const char *GetPluginAuthor()
{
    return "Swiftly Solution";
}

const char *GetPluginVersion()
{
    return "1.0.0";
}

const char *GetPluginName()
{
    return "Join/Leave Messages";
}
