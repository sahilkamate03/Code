import discord
from discord.ext import commands

intents = discord.Intents.default()
intents.members = True
intents.typing = True
intents.presences = True


client= commands.Bot(command_prefix='.', intents=intents)

class Example(commands.Cog):
    def __init__ (self, client):
        self.client = client

    # @commands.Cog.listener()
    # async def on_ready(self):
    #     print('cog is online!')
        
    # @client.command()
    # async def ping(self,ctx):
    #     await ctx.send('pong ')

def setup(client):
    client.add_cog(Example(client))