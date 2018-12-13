from __future__ import division
from random import randint
from os import system
import time


guanyades = 0
seeds = []
players = []
fix = "./MadMax/Game "

print("[+]...")
num_partides = input('NUMERO DE PARTIDES A FER: ')
print("\nPlayers:")
system(fix+' -l > llistaPl.txt')
playersfile = open("llistaPl.txt","r")
numpl = 0
for line in playersfile:
	players.append(line[0:len(line)-1]+' ')
	numpl += 1
playersfile.close()
system('rm llistaPl.txt')
for pl in range(numpl):
	print('['+str(pl)+']  '+players[pl])

myPlayer = input('\nNum del teu player: ')

others = raw_input('Nums de la resta (sense espais, ex: 333): ')
print("JUGADORS TRIATS: "+players[myPlayer]+players[int(others[0])]+players[int(others[1])]+players[int(others[2])])
print('Inici de '+str(num_partides)+' partides...')
time.sleep(2)
for i in range(num_partides):
	print("\n	Partida num: ",i)
	rand_num = randint(1,1000)
	game = fix+players[myPlayer]+players[int(others[0])]+players[int(others[1])]+players[int(others[2])]+"-s "
	game += str(rand_num)
	game += " -i MadMax/default.cnf -o default.res"
	var = system(game)
	res = open("default.res","r")
	ultim = ""
	for line in res:
		if "total_score" in line:
			ultim = line
	list = ultim.split(" ")
	res.close()
	max = 1
	for a in range(1,5):
		if int(list[a]) > int(list[max]):
			max = a
	if max == 1:
		guanyades += 1
	else:
		seeds.append(rand_num)

system("clear")
print("\n")
for i in seeds:
	print('\x1b[1;31m' +"[!]	perds amb seed = "+str(i) + '\x1b[0m')
ratio = (guanyades/num_partides)*100
print('\nJUGADORS TRIATS: '+players[myPlayer]+players[int(others[0])]+players[int(others[1])]+players[int(others[2])])
print('\nRatio de partides guanyades = '+ str(ratio) +'% ('+str(guanyades)+'/'+str(num_partides)+')')
repet = -2
while(repet != -1):
	if(repet != -2):
		print('\n')
		for i in seeds:
			if(i == repet):
				print('\x1b[1;35m' +"[!]	perds amb seed = "+str(i) + '\x1b[0m')
			else:
				print('\x1b[1;31m' +"[!]	perds amb seed = "+str(i) + '\x1b[0m')
		print('\nJUGADORS TRIATS: '+players[myPlayer]+players[int(others[0])]+players[int(others[1])]+players[int(others[2])])
		print('\nRatio de partides guanyades = '+ str(ratio) +'% ('+str(guanyades)+'/'+str(num_partides)+')')
	repet = input('Vols repetir alguna seed? (seed -> repetir| -1 -> acaba): ')
	if(repet != -1):
			game = fix+players[myPlayer]+players[int(others[0])]+players[int(others[1])]+players[int(others[2])]+"-s "
			game += str(repet)
			game += " -i MadMax/default.cnf -o default.res"
			var = system(game)
			veure = raw_input('\x1b[1;34m' +'\nVols visualitzar-la? (y/n) '+ '\x1b[0m' )
			if(veure == 'y'):
				system("cd MadMax/Viewer/ && ./viewer.sh ../default.res && cd ../../")
