module Warmup exposing (..)

import Date exposing (Day(..))
import Date.Extra as Date exposing (Interval(..))
import Html exposing (text)
import List exposing (filter, foldr, map)
import String exposing (join, split)

change : Int -> Result String (Int, Int, Int, Int)
change amount =
    if amount >= 0 then
        Ok (amount // 25, amount % 25 // 10, amount % 25 % 10 // 5, amount % 25 % 10 % 5)
    else
        Err "amount cannot be negative"

stripQuotes : String -> String
stripQuotes =
    split "'" >> join "" >> split "\"" >> join ""

powers : Int -> Int -> Result String (List Int)
powers base limit =
    if base < 0
      then Err "negative base"
    else
        Ok <| List.map (\power -> base ^ power) (List.range 0 <| floor <| logBase (toFloat base) (toFloat limit))

sumOfCubesOfOdds : List Int -> Int
sumOfCubesOfOdds numbers =
    let
        odd numbers = numbers % 2 == 1
        cube numbers = numbers^3
        sum = foldr (+) 0
    in
        numbers |> filter odd |> map cube |> sum

daysBetween : String -> String -> Result String Int
daysBetween dateOne dateTwo =
    let
        date1 = Date.fromString dateOne
        date2 = Date.fromString dateTwo
    in
        case(date1, date2) of
            (Err s, _) -> Err "Bad Date"
            (_, Err s) -> Err "Bad Date"
            (Ok date1, Ok date2) -> Ok <|
                Date.diff Day
                (date1)
                (date2)
