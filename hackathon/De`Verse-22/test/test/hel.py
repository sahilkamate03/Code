d = {'surajchavan': {'created_at': 'today', 'profile_url': '', 'username': 'surajchavan'}}
print(d)
d.pop('surajchavan', None)
print(d)
for value in d.values():
    print(value)