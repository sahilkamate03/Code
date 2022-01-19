import discord
from discord.ext import commands
import random
import os 

token='OTE5ODg1MjM4OTY3MTA3NjA0.YbcT4w.YfFdSKwL6MKwcNOz4a7xjgBt7cM'
intents = discord.Intents.default()
intents.members = True
intents.typing = True
intents.presences = True


client= commands.Bot(command_prefix='.', intents=intents)

@client.event
async def on_ready():
    print(f'Ready to rock!!')

@client.event
async def on_member_join(member):
    print(f'{member} has joined the server')

@client.event
async def on_member_remove(member):
    print(f'{member} has left the server')

@client.command()
async def ping(ctx):
    await ctx.send(f'pong {round(client.latency * 1000)}ms')

@client.command(aliases=['8ball','eightball'])
async def _8ball(ctx,* ,_8ball_question):
    responses = ["As I see it, yes.",
    "Ask again later.", 
    "Better not tell you now.", 
    "Cannot predict now.", 
    "Concentrate and ask again.",
    "It is certain.", 
    "Dont count on it.", 
    "It is decidedly so.", 
    "Most likely.",
    "My reply is no.",
    "My sources say no.",
    "Outlook not so good.",
    "Outlook good.", 
    "Reply hazy, try again.", 
    "Signs point to yes.",
    "Very doubtful.",
    "Without a doubt.",
    "Yes.",
    "Yesdefinitely.",
    "You may rely on it."]
    
    await ctx.send(f'Question: {_8ball_question} \n Answer: {random.choice(responses)}')

@client.command()
async def clear(ctx, amount=5):  
    await ctx.channel.purge(limit=amount+1)

@client.command()
async def kick(ctx,member : discord.Member,*,reason=None):
    await member.kick(reason= reason)

@client.command()
async def ban(ctx,member : discord.Member,*,reason=None):
    await member.ban(reason= reason)
    await ctx.send(f'banned {member.mention}')

@client.command(name='unbans')
async def _unban(ctx, id: int):
    user = await client.fetch_user(id)
    await ctx.guild.unban(user)

@client.command()
async def unban(ctx,*, member):
    banned_user= await ctx.guild.bans()
    print(banned_user)
    member_name, member_descriminator = member.split('#')

    for ban_entry in banned_user:
        user= ban_entry.user

        if (user.name, user.discriminator)==(member_name, member_descriminator):
            await ctx.guild.unban(user)
            await ctx.send(f'{user.mention} has been unbanned')
            return

@client.command()
async def load(ctx, extension):
    client.load_extension(f'{cog.extension}')

@client.command()
async def unload(ctx, extension):
    client.unload_extension(f'{cog.extension}')  

for filename in os.listdir('./cogs'):
    if filename.endswith('.py'):
        client.load_extension(f'cogs.{filename[:-3]}')
client.run(token)

