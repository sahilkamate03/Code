import discord
from discord.ext import commands

intents = discord.Intents.default()
intents.members = True
intents.typing = True
intents.presences = True


client= commands.Bot(command_prefix='.', intents=intents)

class Moderation(commands.Cog):

    def __init__ (self, client):
        self.client = client
    
    @client.command()
    @commands.has_permissions(manage_messages=True)
    async def clear(self, ctx, amount : int):  
        await ctx.channel.purge(limit=amount+1)

    @client.command()
    @commands.has_permissions(kick_members=True)
    async def kick(self, ctx,member : discord.Member,*,reason=None):
        await member.kick(reason= reason)

    @client.command()
    @commands.has_permissions(ban_members=True)
    async def ban(self, ctx,member : discord.Member,*,reason=None):
        await member.ban(reason= reason)
        await ctx.send(f'banned {member.mention}')

    @commands.command(name='unban')
    @commands.has_permissions(ban_members=True)
    async def _unban(self, ctx, id: int ,*, reason=None):
        user = await client.fetch_user(id)
        print(user)
        await ctx.guild.unban(user)
        await ctx.send(f'ID no {id} has been unbanned. \n Reason: {reason}')

def setup(client):
    client.add_cog(Moderation(client))
 