let url: string = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

type item = {
  label: string,
  value: string,
};

let decodeItem = json => {
  Json.Decode.{
    label: json |> field("label", string),
    value: json |> field("value", string),
  };
};

let fetchCountries: option(array(item)) => array(item) =
  fun
  | Some(arr) => arr
  | None => [|{label: "", value: "Loading..."}|];

let decode = json =>
  json
  ->Js.Json.decodeArray
  ->Belt.Option.getExn
  ->Belt.Array.map(item => item |> decodeItem);
