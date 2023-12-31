let url: string = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

type item = {
  label: string,
  value: string,
};
// Melange Json for decode
let decodeItem = json => {
  Json.Decode.{
    label: json |> field("label", string),
    value: json |> field("value", string),
  };
};

let countryLoadState: option(array(item)) => array(item) =
  fun
  | Some(arr) => arr
  | None => [|{label: "Loading...", value: "xx"}|];

let decode = json =>
  json
  ->Js.Json.decodeArray
  // ensures safety in the case we dont get values back
  ->Belt.Option.getExn
  ->Belt.Array.map(item => item |> decodeItem);
