module Cylinder exposing(..)

type alias Cylinder = {radius : Float, height : Float}

new =
    {radius = 1.0, height = 1.0}

volume : Cylinder -> Float
volume cylinder =
    pi * (cylinder.radius)^2 * cylinder.height

surfaceArea : Cylinder -> Float
surfaceArea cylinder =
    2 * pi * cylinder.radius * cylinder.height + 2 * pi * (cylinder.radius)^2

stretch : Int -> Cylinder -> Cylinder
stretch factor cylinder =
    {cylinder | height = cylinder.height * toFloat factor}

widen : Int -> Cylinder -> Cylinder
widen factor cylinder =
    {cylinder | radius = cylinder.radius * toFloat factor}
