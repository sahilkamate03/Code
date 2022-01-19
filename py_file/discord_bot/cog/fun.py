import discord
from discord.ext import commands
import random

intents = discord.Intents.default()
intents.members = True
intents.typing = True
intents.presences = True


client= commands.Bot(command_prefix='.', intents=intents)

class Fun(commands.Cog):
    
    def __init__ (self, client):
        self.client = client

    @client.command(aliases=['8ball','eightball'])
    async def _8ball(self,ctx,* ,_8ball_question):
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

def setup(client):
    client.add_cog(Fun(client))