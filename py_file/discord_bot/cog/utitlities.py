import discord
from discord.ext import commands

intents = discord.Intents.default()
intents.members = True
intents.typing = True
intents.presences = True


client= commands.Bot(command_prefix='.', intents=intents)

class Utility(commands.Cog):
    
    # @client.event
    # async def on_member_join(self,member):
    #     channel = client.get_channel(928640243891056721)
    #     await channel.send(f'{member} has joined the server')
        

    # @client.event
    # async def on_member_remove(self,member):
    #     channel = client.get_channel(928640243891056721)
    #     await channel.send(f'{member} has left the server')
        

    @client.command()
    async def ping(self,ctx):
        await ctx.send(f'ping {client.latency * 1000}ms')
        print(client.latency)

def setup(client):
    client.add_cog(Utility(client))