t = int(input())
for rec in range(1, t+1):  # number of recipes to rescale
    print("Recipe #", rec)
    r, p, d = map(int, input().split())
    scf = float(d)/p  # scaling factor
    scw = None
    recipe = []
    for _ in range(r):  # 1≤R≤20 is the number of ingredients
        na, we, per = input().split()  # <name>   <weight>   <percentage>
        recipe.append([na, per])  # Saving the recipe for later use

        if (scw is None and float(per) == 100.0):  # finding the main ingredient with 100 percent
            scw =  float(we) * scf
    print(*map(lambda x: "{} {}".format(x[0], round(float(x[1]) * scw * 0.01, 1)), recipe), sep='\n')
    print(40*"-")
