import Html exposing (Html, body, input, text, h1, p)
import Html.Attributes exposing (style, value, type_)
import Html.Events exposing (onInput)
import Date exposing (Day(..))
import Date.Extra as Date exposing (Interval(..))

type alias Model = { fromDate: String, toDate: String }
type Msg = ChangeFromDate String | ChangeToDate String

daysBetween : String -> String -> String
daysBetween dateOne dateTwo =
    let
        date1 = Date.fromString dateOne
        date2 = Date.fromString dateTwo
    in
        case(date1, date2) of
            (Err s, _) -> ""
            (_, Err s) -> ""
            (Ok date1, Ok date2) ->
                toString (Date.diff Day
                (date1)
                (date2))

main =
    Html.beginnerProgram { model = model, view = view, update = update }

model : Model
model = {fromDate = "", toDate = ""}

update : Msg -> Model -> Model
update msg model =
    case msg of
        ChangeFromDate d1 -> { model | fromDate = d1 }
        ChangeToDate d2 -> { model | toDate = d2 }

view : Model -> Html Msg
view model =
    body [style [("textAlign", "center")]]
        [ h1 [] [text "Date Calculator"]
        , p [] [text "From Date ", input [type_ "date", onInput ChangeFromDate, value model.fromDate] []]
        , p [] [text "To Date ", input [type_ "date", onInput ChangeToDate, value model.toDate] []]
        , p [] [text <| "is " ++ daysBetween model.fromDate model.toDate ++ " days"]
        ]
