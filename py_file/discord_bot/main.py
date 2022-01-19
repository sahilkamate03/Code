import discord
from discord.ext import commands, tasks
from itertools import cycle
import random
import requests 
import json
import os 
import datetime

token='OTE5ODg1MjM4OTY3MTA3NjA0.YbcT4w.YfFdSKwL6MKwcNOz4a7xjgBt7cM'
intents = discord.Intents.default()
intents.members = True
intents.typing = True
intents.presences = True


client= commands.Bot(command_prefix='.', intents=intents, help_command=commands.DefaultHelpCommand())


def  developer(ctx):
    return ctx.author.id== 866933932222185492

@client.event
async def on_ready():
    # await client.change_presence(status=discord.Status.idle, activity= discord.Game("Hello Buddy!"))
    change_status.start()
    print(f'Ready to rock!!')

@client.event
async def on_member_join(member):
    print(f'{member} has joined the server')
    channel = client.get_channel(928640243891056721)
    await channel.send(f'{member} has joined the server')

@client.event
async def on_member_remove(member):
    print(f'{member} has left the server')
    channel = client.get_channel(928640243891056721)
    await channel.send(f'{member} has left the server')

# @client.command()
# async def ping(ctx):
#     await ctx.send(f'pong {round(client.latency * 1000)}ms')

# @client.command(aliases=['8ball','eightball'])
# async def _8ball(ctx,* ,_8ball_question):
#     responses = ["As I see it, yes.",
#     "Ask again later.", 
#     "Better not tell you now.", 
#     "Cannot predict now.", 
#     "Concentrate and ask again.",
#     "It is certain.", 
#     "Dont count on it.", 
#     "It is decidedly so.", 
#     "Most likely.",
#     "My reply is no.",
#     "My sources say no.",
#     "Outlook not so good.",
#     "Outlook good.", 
#     "Reply hazy, try again.", 
#     "Signs point to yes.",
#     "Very doubtful.",
#     "Without a doubt.",
#     "Yes.",
#     "Yesdefinitely.",
#     "You may rely on it."]
    
#     await ctx.send(f'Question: {_8ball_question} \n Answer: {random.choice(responses)}')

# @client.command()
# @commands.has_permissions(manage_messages=True)
# async def clear(ctx, amount : int):  
#     await ctx.channel.purge(limit=amount+1)

# @client.command()
# async def kick(ctx,member : discord.Member,*,reason=None):
#     await member.kick(reason= reason)

# @client.command()
# async def ban(ctx,member : discord.Member,*,reason=None):
#     await member.ban(reason= reason)
#     await ctx.send(f'banned {member.mention}')

# @client.command(name='unbans')
# async def _unban(ctx, id: int):
#     user = await client.fetch_user(id)
#     await ctx.guild.unban(user)

# @client.command()
# async def unban(ctx,*, member):
#     banned_user= await ctx.guild.bans()
#     print(banned_user)
#     member_name, member_descriminator = member.split('#')

#     for ban_entry in banned_user:
#         user= ban_entry.user

#         if (user.name, user.discriminator)==(member_name, member_descriminator):
#             await ctx.guild.unban(user)
#             await ctx.send(f'{user.mention} has been unbanned')
#             return


@client.command()
@commands.check(developer)
async def load(ctx, extension):
    client.load_extension(f'cog.{extension}')
    await ctx.send("Load Succesful!")

@client.command()
@commands.check(developer)
async def unload(ctx, extension):
    client.unload_extension(f'cog.{extension}')   
    await ctx.send("Unload Succesful!")

@client.command()
@commands.check(developer)
async def reload(ctx, extension):
    client.unload_extension(f'cog.{extension}')  
    client.load_extension(f'cog.{extension}')    
    await ctx.send("Reload Succesful!")

for filename in os.listdir('./cog'):
    if filename.endswith('.py'):
        client.load_extension(f'cog.{filename[:-3]}')


status = cycle(['hello buddy','this status is changing','wth','.help'])
@tasks.loop(seconds=10)
async def change_status():
    await client.change_presence(activity=discord.Game(next(status)))

# @client.event
# async def on_command_error(ctx,error):
#     # if isinstance(error, commands.MissingRequiredArgument(param)):
#     #     await ctx.send('Plz provide all req arguement')
    
#     if isinstance(error, commands.CommandNotFound):
#         await ctx.send('Invalid command//')

# @clear.error
# async def clear_error(ctx, error):
#     await ctx.send('plz provide the number of msg to be deleted')

# @client.event
# def new(ctx):
#     embed = discord.Embed(title="title ~~(did you know you can have markdown here too?)~~", colour=discord.Colour(0xe04077), url="https://discordapp.com", description="this supports [named links](https://discordapp.com) on top of the previously shown subset of markdown. ```\nyes, even code blocks```", timestamp=datetime.datetime.utcfromtimestamp(1642072840))

#     embed.set_image(url="https://cdn.discordapp.com/embed/avatars/0.png")
#     embed.set_thumbnail(url="https://cdn.discordapp.com/embed/avatars/0.png")
#     embed.set_author(name="author name", url="https://discordapp.com", icon_url="https://cdn.discordapp.com/embed/avatars/0.png")
#     embed.set_footer(text="footer text", icon_url="https://cdn.discordapp.com/embed/avatars/0.png")

#     embed.add_field(name="🤔", value="some of these properties have certain limits...")
#     embed.add_field(name="😱", value="try exceeding some of them!")
#     embed.add_field(name="🙄", value="an informative error should show up, and this view will remain as-is until all issues are fixed")
#     embed.add_field(name="<:thonkang:219069250692841473>", value="these last two", inline=True)
#     embed.add_field(name="<:thonkang:219069250692841473>", value="are inline fields", inline=True)

    
#     async await client.say(content="this `supports` __a__ **subset** *of* ~~markdown~~ 😃 ```js\nfunction foo(bar) {\n  console.log(bar);\n}\n\nfoo(1);```", embed=embed)

@client.command()
async def repeat(ctx, times: int, content='repeating...'):
    """Repeats a message multiple times."""
    for i in range(times):
        await ctx.send(content)

# @client.command()
# async def naughty(ctx):
    # number= random.randint(0, 250)
    # n= random.randint(0, 10)
    # # r = requests.get(f'https://www.eporner.com/api/v2/video/search/?query=teen&per_page=10&page={number}&thumbsize=big&order=top-weekly&format=json')
    # response = requests.get(f"https://api.redtube.com/?data=redtube.Videos.searchVideos&output=json&page={number}&tags[]=Teen&thumbsize=medium  ")
    # data = json.loads(response.text)
    
    # await ctx.send(data['videos'][n]['video']["thumb"])
    # await ctx.channel.send("Title: ")
    # await ctx.channel.send(data['videos'][n]['video']["title"])
    # await ctx.channel.send("Duration: ")
    # await ctx.channel.send(data['videos'][n]['video']["duration"])
    # await ctx.channel.send("Like: ")
    # await ctx.channel.send(data['videos'][n]['video']["rating"])
    # await ctx.channel.send("Dislike: ")
    # await ctx.channel.send(data['videos'][n]['video']["ratings"])
    # await ctx.channel.send("URL: ")
    # await ctx.channel.send(data['videos'][n]['video']["url"])


    
# @client.command()
# async def test(ctx):
#     # embed = discord.Embed(title="title ~~(did you know you can have markdown here too?)~~", colour=discord.Colour(0xb18f74), url="https://discordapp.com", description="this supports [named links](https://discordapp.com) on top of the previously shown subset of markdown. ```\nyes, even code blocks```", timestamp=datetime.datetime.utcfromtimestamp(1642155636))

#     # embed.set_image(url="https://cdn.discordapp.com/embed/avatars/0.png")
#     # embed.set_thumbnail(url="https://cdn.discordapp.com/embed/avatars/0.png")
#     # embed.set_author(name=ctx.author, url="https://discordapp.com", icon_url= user.display_avatar)
#     embed.set_footer(text=f"Requested by {ctx.author}", icon_url=
#     ctx.author.avatar_url)

#     # embed.add_field(name="Duration", value="some of these properties have certain limits...")
#     # embed.add_field(name="Ratings", value="try exceeding some of them!")
#     # embed.add_field(name="<:thonkang:219069250692841473>", value="these last two", inline=True)
#     # embed.add_field(name="<:thonkang:219069250692841473>", value="are inline fields", inline=True)

#     # await client.say(content="this `supports` __a__ **subset** *of* ~~markdown~~ 😃 ```js\nfunction foo(bar) {\n  console.log(bar);\n}\n\nfoo(1);```", embed=embed)
#     embed = discord.Embed(title='Test Embed', description='hello world')
#     embed.colour = 0xFFFFFF  # can be set in 'discord.Embed()' too
#     embed.set_image(url= ctx.author.avatar_url)

#     await ctx.send(embed=embed)
    
  
client.run(token)

