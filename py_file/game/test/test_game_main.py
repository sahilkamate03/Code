from urllib.request import urlopen
from bs4 import BeautifulSoup

htmldata = urlopen('https://xhamster17.desi/')
soup = BeautifulSoup(htmldata, 'html.parser')
images = soup.find_all('img')

for item in images:
	print(item['src'])

import discord
from discord.ext import commands
import datetime
import requests
import json
import random
from urllib.request import urlopen
from bs4 import BeautifulSoup


intents = discord.Intents.default()
intents.members = True
intents.typing = True
intents.presences = True


client= commands.Bot(command_prefix='$', intents=intents)

class Testing(commands.Cog):

    @client.command()
    async def test(self,ctx):
        number= random.randint(0, 250)
        n= random.randint(0, 10)
        # r = requests.get(f'https://www.eporner.com/api/v2/video/search/?query=teen&per_page=10&page={number}&thumbsize=big&order=top-weekly&format=json')
        response = requests.get(f"https://api.redtube.com/?data=redtube.Videos.searchVideos&output=json&page={number}&tags[]=Teen&thumbsize=medium  ")
        data = json.loads(response.text)
        provider='https://is5-ssl.mzstatic.com/image/thumb/Purple114/v4/ef/9e/08/ef9e0839-976c-2934-ab65-5b70fb29dc4f/source/512x512bb.jpg'
        embed = discord.Embed(title='Video Suggestion', description='I am suggesting a vidoe of your interest')
        embed.colour = 0xFFFFFF  # can be set in 'discord.Embed()' too
        embed.set_image(url= data['videos'][n]['video']["thumb"])
        embed.set_thumbnail(url= provider)
        embed.set_footer(text=f"Requested by {ctx.author} at {datetime.datetime.utcfromtimestamp(1642155636)}", icon_url=
        ctx.author.avatar_url)
        embed.set_author(name=ctx.author, url="https://discordapp.com", icon_url= ctx.author.avatar_url)
        embed.add_field(name="Title", value=data['videos'][n]['video']["title"])
        embed.add_field(name="Duration", value=data['videos'][n]['video']["duration"])
        embed.add_field(name="Ratings", value=data['videos'][n]['video']["rating"])
        embed.add_field(name="URL", value=data['videos'][n]['video']["url"])

        await ctx.send(embed=embed)

    @client.command()
    async def s(self,ctx,*,search):
        number= random.randint(0, 5)
        
        n= random.randint(0,10)
        # r = requests.get(f'https://www.eporner.com/api/v2/video/search/?query=teen&per_page=10&page={number}&thumbsize=big&order=top-weekly&format=json')
        response = requests.get(f"https://api.redtube.com/?data=redtube.Videos.searchVideos&output=json&search={search}&page={number}&thumbsize=medium")
        data = json.loads(response.text)
        provider='https://is5-ssl.mzstatic.com/image/thumb/Purple114/v4/ef/9e/08/ef9e0839-976c-2934-ab65-5b70fb29dc4f/source/512x512bb.jpg'
        embed = discord.Embed(title='Video Suggestion', description='I am suggesting a vidoe of your interest')
        embed.colour = 0xFFFFFF  # can be set in 'discord.Embed()' too
        embed.set_image(url= data['videos'][n]['video']["thumb"])
        embed.set_thumbnail(url= provider)
        embed.set_footer(text=f"Requested by {ctx.author} at {datetime.datetime.utcfromtimestamp(1642155636)}", icon_url=
        ctx.author.avatar_url)
        embed.set_author(name=ctx.author, url="https://discordapp.com", icon_url= ctx.author.avatar_url)
        embed.add_field(name="Title", value=data['videos'][n]['video']["title"])
        embed.add_field(name="Duration", value=data['videos'][n]['video']["duration"])
        embed.add_field(name="Ratings", value=data['videos'][n]['video']["rating"])
        embed.add_field(name="URL", value=data['videos'][n]['video']["url"])

        await ctx.send(embed=embed)

    @client.command()
    async def s(self,ctx,*,search):
        htmldata = urlopen('https://xhamster17.desi/')
        soup = BeautifulSoup(htmldata, 'html.parser')
        images = soup.find_all('img')

        for item in images:
            await ctx.send(item['src'])


def setup(client):
    client.add_cog(Testing(client))
