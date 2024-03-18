import madgraph.core.drawing as drawing

def remove_diag(diag, model):
    draw = drawing.FeynmanDiagram(diag, model)
    draw.load_diagram()

    for p in draw.lineList:
        # enforce presence of Z' (or W to ensure that decay diagrams are not removed)
        if p.id in [32, 24, -24]:
            return False
            
    return True
