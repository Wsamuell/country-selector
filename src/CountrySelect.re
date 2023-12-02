open Bindings;
open CountryData;
open Icons;
open SharedStyle;

module Style = {
  let dropdown =
    ReactDOM.Style.make(
      ~position="relative",
      ~width="230px",
      ~height="429px",
      ~fontFamily="Arial",
      ~fontSize="14px",
      (),
    );
  let button =
    ReactDOM.Style.make(
      ~alignItems="center",
      ~backgroundColor=colorToHex(Light),
      ~border=
        "1px solid var(--light-border-control-alpha, rgba(0, 0, 0, 0.20))",
      ~borderRadius="3px",
      ~columnGap="6px",
      ~display="flex",
      ~height="26px",
      ~justifyContent="space-between",
      ~minWidth="144px",
      ~padding="4px 10px",
      (),
    );
  let flag = ReactDOM.Style.make(~width="14px", ~height="14px", ());
  let divPad =
    ReactDOM.Style.make(
      ~padding="4px",
      ~textOverflow="ellipsis",
      ~overflow="hidden",
      ~maxWidth="150px",
      ~whiteSpace="nowrap",
      (),
    );
  let icon = {
    ReactDOM.Style.make(~padding="3px", ());
  };

  // Bring back blanket after fixing the dropdown
  let blanket = {
    ReactDOM.Style.make// ~bottom="0",
                       // ~left="0",
                       // ~top="0",
                       (); // ~position="fixed",
 // ~right="0",
                       // ~zIndex="1",
  };
  let menu = {
    ReactDOM.Style.make(
      ~backgroundColor=colorToHex(Light),
      ~marginTop="3px",
      ~position="absolute",
      ~zIndex="2",
      ~width="100%",
      (),
    );
  };

  let theme =
    ReactDOM.Style.make(
      ~borderRadius="0px",
      ~backgroundColor=colorToHex(Dark),
      (),
    );
};
module CustomStyle = {
  open Select;
  let customStyle = {
    control: props =>
      ReactDOMStyle.combine(
        props,
        ReactDOMStyle.make(~display="flex", ~flexDirection="row-reverse", ()),
      ),
  };
  let customTheme = {
    borderRadius: "0px 0px 3px 3px",
    colors: {
      primary: colorToHex(Hover),
      primary25: colorToHex(Hover),
    },
    spacing: {
      baseUnit: 5,
      controlHeight: 0,
      menuGutter: 1,
    },
  };
};

module Option = {
  [@react.component]
  let make = (~internalProps, ~data) => {
    <div>
      <span className={"fi fi-" ++ data.value} />
      <Option props=internalProps />
    </div>;
  };
};

module Menu = {
  [@react.component]
  let make = (~children) => {
    <div style=Style.menu> children </div>;
  };
};
module Blanket = {
  [@react.component]
  let make = (~onClick) => {
    <div style=Style.blanket onClick />;
  };
};

module Dropdown = {
  [@react.component]
  let make = (~target, ~children, ~isOpen, ~onClose) => {
    <div style=Style.dropdown>
      target
      {isOpen ? <Menu> children </Menu> : React.null}
      {isOpen ? <Blanket onClick=onClose /> : React.null}
    </div>;
  };
};

[@react.component]
let make = () => {
  let (active, setActive) = React.useState(() => false);
  let (countries, setCountries) =
    React.useState(() => countryLoadState(None));
  let (selectedCountry, setSelectedCountry) =
    React.useState(() => {label: "Select A country", value: "xx"});
  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json => json |> decode |> resolve)
          |> then_(itemArray =>
               countryLoadState(Some(itemArray)) |> resolve
             )
          |> then_(array => setCountries(_ => array) |> resolve)
        );
      Some(() => ());
    },
    [||],
  );
  <Dropdown
    isOpen=active
    onClose={_ => setActive(_ => false)}
    target={
      <button onClick={_ => setActive(prev => !prev)} style=Style.button>
        <span className={"fi fi-" ++ selectedCountry.value} style=Style.flag />
        <div style=Style.divPad> {React.string(selectedCountry.label)} </div>
        <Arrow style=Style.icon />
      </button>
    }>
    <Select
      closeMenuOnSelect=true
      components={
        dropdownIndicator: _ => <Search />,
        indicatorSeparator: false,
        option: ({data} as internalProps: Select.optionProps) =>
          <Option internalProps data />,
      }
      multi=false
      name="Country Selector"
      noOptionsMessage={_ => "Country Not Found!"}
      onChange={value => setSelectedCountry(_ => value)}
      options=countries
      autoFocus=true
      backspaceRemovesValue=false
      controlShouldRenderValue=false
      hideSelectedOptions=false
      isClearable=false
      menuIsOpen=true
      placeholder="Search"
      tabSelectsValue=false
      theme=CustomStyle.customTheme
      styles=CustomStyle.customStyle
      value={selectedCountry.label}
    />
  </Dropdown>;
};
