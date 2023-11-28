module Arrow = {
  [@react.component]
  let make = (~style: ReactDOMStyle.t) => {
    <div style>
      <svg
        width="8"
        height="8"
        viewBox="0 0 8 8"
        fill="none"
        xmlns="http://www.w3.org/2000/svg">
        <g id="Icon Set / Triangle.Neutral">
          <path
            id="Path"
            fillRule="evenodd"
            clipRule="evenodd"
            d="M0 2H8L4 7L0 2Z"
            fill="#333333"
          />
        </g>
      </svg>
    </div>;
  };
};
